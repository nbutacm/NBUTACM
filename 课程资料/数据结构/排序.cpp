/*******************************************************************/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void Print(const char s[][20], int n) {
  for (int i = 0; i < n; i++) {
    cout << s[i] << (i == n - 1 ? "\n" : " ");
  }
}

/********************************************/
void BubbleSort(char s[][20], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(s[i], s[j]) == 1) {
        swap(s[i], s[j]);
      }
    }
  }
}

/**********************************************************/

void InsertSort(char s[][20], int n) {
  int  i, j;
  char temp[20];
  for (i = 1; i < n; i++) { // i之前为有序
    strcpy(temp, s[i]);
    for (j = i - 1; j >= 0; j--) {
      if (strcmp(temp, s[j]) == -1) {
        strcpy(s[j + 1], s[j]);
      }
      else break;
    }
    strcpy(s[j + 1], temp);
  }
}

/*******************************************************************************/

int BinarySreach(int l, int r, const char s[][20], const char temp[]) {
  while (l <= r) {
    int mid = (l + r) / 2;
    if (strcmp(s[mid], temp) == 1) {
      r--;
    }
    else {
      l++;
    }
  }
  return l;
}

void BinaryInsertSort(char s[][20], int n) {
  int i, j;
  for (i = 1; i < n; i++) { // i之前为有序
    char temp[20];
    strcpy(temp, s[i]);
    int pos = BinarySreach(0, i - 1, s, temp);
    for (j = i - 1; j >= pos; j--) {
      strcpy(s[j + 1], s[j]);
    }
    strcpy(s[j + 1], temp);
  }
}

/************************************************************/

void SelectSort(char s[][20], int n) {
  int i, j, pos;
  for (i = 0; i < n; i++) {
    char temp[20];
    pos = i;
    strcpy(temp, s[i]);
    for (j = i; j < n; j++) {
      if (strcmp(temp, s[j]) == 1) {
        strcpy(temp, s[j]);
        pos = j;
      }
    }
    swap(s[pos], s[i]);
  }
}

/***************************************************/
void QuickSort(char s[][20], int l, int r) {
  if (l < r) {
    int  i = l, j = r;
    char temp[20];
    strcpy(temp, s[l]);
    while (i < j) {
      while (i < j && strcmp(s[j], temp) == 1) {
        j--;
      }
      strcpy(s[i], s[j]);
      while (i < j && strcmp(s[i], temp) == -1) {
        i++;
      }
      strcpy(s[j], s[i]);
    }
    strcpy(s[i], temp);
    QuickSort(s, l,     i - 1);
    QuickSort(s, i + 1, r);
  }
}

/******************************************************/
void ShellSort(char s[][20], int n) {
  char temp[20];
  for (int len = n / 2; len > 0; len /= 2) {
    for (int k = 0; k < len; k++) {
      for (int i = k; i < n; i += len) {
        for (int j = i + len; j < n; j += len) {
          if (strcmp(s[i], s[j]) == 1) {
            swap(s[i], s[j]);
          }
        }
      }
    }
  }
}

/******************************************************/

void Merge(char s[][20], char t[][20], int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;
  while (i != mid + 1 && j != r + 1) {
    if (strcmp(s[i], s[j]) == 1) {
      strcpy(t[k], s[j]);
      k++; j++;
    }
    else {
      strcpy(t[k], s[i]);
      k++; i++;
    }
  }
  while (i != mid + 1) {
    strcpy(t[k], s[i]);
    k++; i++;
  }
  while (j != r + 1) {
    strcpy(t[k], s[j]);
    k++; j++;
  }
  for (i = l; i <= r; i++) {
    strcpy(s[i], t[i]);
  }
}

void MergeSort(char s[][20], char t[][20], int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    MergeSort(s, t, l,       mid);
    MergeSort(s, t, mid + 1, r);
    Merge(s, t, l, mid, r);
  }
}

/******************************************************/
void HeapAdjust(char s[][20], int i, int n) {
  int nChild;
  int nTemp;
  for (i; 2 * i + 1 < n; i = nChild) {
    nChild = 2 * i + 1;
    if ((nChild < n - 1) && (strcmp(s[nChild + 1], s[nChild]) == 1)) {
      ++nChild;
    }
    if (strcmp(s[i], s[nChild]) == -1) {
      swap(s[i], s[nChild]);
    }
    else break;
  }
}

void HeapSort(char s[][20], int n)
{
  int i;
  for (i = n / 2 - 1; i >= 0; --i) {
    HeapAdjust(s, i, n);
  }
  for (i = n - 1; i > 0; --i) {
    swap(s[0], s[i]);
    HeapAdjust(s, 0, i);
  }
}

/******************************************************/

int main() {
  char s[][20] = { "while", "if", "else", "do", "for", "switch", "case" };
  int  n       = 7;

  // BubbleSort(s,n);            //冒泡排序
  // InsertSort(s,n);            //插入排序
  // BinaryInsertSort(s,n);      //插入排序二分优化
  SelectSort(s, n); //选择排序
  // QuickSort(s,0,n-1);         //快速排序
  // ShellSort(s,n);             //希尔排序
  char t[7][20];

  // MergeSort(s,t,0,n-1);       //归并排序
  // HeapSort(s,n);              //堆排序
  Print(s, n);
}