// Copyright 2024 <dimrimoff>

#include <ncurses.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PATH 1024

int  DirectoryList(WINDOW *win, const char *path, int highlight, int start_item) {
  struct dirent **namelist;
  int n = scandir(path, &namelist, NULL, alphasort);
  if (n < 0) {
    wprintw(win, "Не удалось открыть директорию: %s\n", path);
    return -1;
  }

  for (int i = 0; i < n - start_item; i++) {
    if (i + start_item == highlight) {
      wattron(win, A_REVERSE);
    }
    mvwprintw(win, i + 1, 2, "%s\n", namelist[i + start_item]->d_name);
    if (i + start_item == highlight) {
      wattroff(win, A_REVERSE);
    }
  }
  for (int i = 0; i < n; i++) {
    free(namelist[i]);
  }
  free(namelist);
  return n;
}

int UpdateDirectory(WINDOW *win, char *path, int *highlight, int start_item) {
  werase(win);
  int directory_item_num = DirectoryList(win, path, *highlight, start_item);
  box(win, 0, 0);
  mvwprintw(win, 0, 0, " %s \n", path);
  wrefresh(win);
  return directory_item_num;
}

void ChangeDirectory(char *path, const char *new_dir) {
  if (strcmp(new_dir, "..") == 0) {
    char *last_slash = strrchr(path, '/');
    if (last_slash != NULL) {
      if (last_slash == path) {
        path[1] = '\0';
      } else {
        *last_slash = '\0';
      }
    }
  } else {
    size_t path_len = strlen(path);
    size_t new_dir_len = strlen(new_dir);
    if (path_len + new_dir_len + 2 < MAX_PATH) {
      if (path_len != 1) strcat(path, "/");
      strcat(path, new_dir);
    } else {
      fprintf(stderr, "Ошибка: превышен размер пути\n");
    }
  }
}

int main() {
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  curs_set(0);
  
  int height, width, startx, starty;
  height = LINES;
  width = COLS/2 - 1;
  starty = 0;
  startx = 0;

  WINDOW *left_win = newwin(height, width, starty, startx);
  WINDOW *right_win = newwin(height, width, starty, startx + width + 2);
  
  char left_path[MAX_PATH], right_path[MAX_PATH];
  getcwd(left_path, sizeof(left_path));
  getcwd(right_path, sizeof(right_path));

  int left_highlight = 0;
  int right_highlight = 0;
  int active_panel = 0; // 0 - левая панель, 1 - правая панель
  int left_item_num = 0;
  int right_item_num = 0;
  int left_start_item = 0;
  int right_start_item =0;

  
  while (1) {
    
    left_item_num =  UpdateDirectory(left_win, left_path, &left_highlight, left_start_item);
    right_item_num = UpdateDirectory(right_win, right_path, &right_highlight, right_start_item);

    int ch = getch();
    switch (ch) {
      case KEY_UP:
        if (active_panel == 0 && left_highlight > 0) {
          left_highlight--;
          if (left_highlight < left_start_item) {
            left_start_item--;
          }
        } else if (active_panel == 1 && right_highlight > 0) {
          right_highlight--;
          if (right_highlight < right_start_item) {
            right_start_item--;
          }
        }
        break;
      case KEY_DOWN:
        if (active_panel == 0 && left_highlight < left_item_num - 1) {
          left_highlight++;
          if (left_highlight > left_start_item + LINES - 3 && left_start_item < left_item_num - LINES + 2) {
            left_start_item ++;
          }
        } else if (active_panel == 1 && right_highlight < right_item_num - 1) {
          right_highlight++;
          if (right_highlight > right_start_item + LINES - 3 && right_start_item < right_item_num - LINES + 2) {
            right_start_item ++;
          }
        }
        break;
      case '\t': 
        active_panel = !active_panel;
        break;
      case '\n': 
        if (active_panel == 0) {
          struct dirent **namelist;
          int n = scandir(left_path, &namelist, NULL, alphasort);
          if (n > 0 && left_highlight < n) {
            struct stat st;
            char new_path[MAX_PATH];
            if (snprintf(new_path, MAX_PATH, "%s/%s", left_path, namelist[left_highlight]->d_name) < MAX_PATH) {
              if (stat(new_path, &st) == 0 && S_ISDIR(st.st_mode) && strcmp(namelist[left_highlight]->d_name, ".") != 0) {
                ChangeDirectory(left_path, namelist[left_highlight]->d_name);
                left_highlight = 1;
                left_start_item = 0;
              }
            } else {
              fprintf(stderr, "Ошибка: превышен размер пути\n");
            }
            for (int i = 0; i < n; i++) {
              free(namelist[i]);
            }
            free(namelist);
          }
        } else if (active_panel == 1) {
          struct dirent **namelist;
          int n = scandir(right_path, &namelist, NULL, alphasort);
          if (n > 0 && right_highlight < n) {
            struct stat st;
            char new_path[MAX_PATH];
            if (snprintf(new_path, MAX_PATH, "%s/%s", right_path, namelist[right_highlight]->d_name) < MAX_PATH) {
              if (stat(new_path, &st) == 0 && S_ISDIR(st.st_mode) && strcmp(namelist[right_highlight]->d_name, ".") != 0) {
                ChangeDirectory(right_path, namelist[right_highlight]->d_name);
                right_highlight = 1;
                right_start_item = 0;
              }
            } else {
              fprintf(stderr, "Ошибка: превышен размер пути\n");
            }
            for (int i = 0; i < n; i++) {
              free(namelist[i]);
            }
            free(namelist);
          }
        }
        break;
      case 'q': 
        endwin();
        return 0;
    }
  }

  endwin();
  return 0;
}
