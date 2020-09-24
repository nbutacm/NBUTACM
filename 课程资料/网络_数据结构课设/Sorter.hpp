#ifndef _SORTHER_
#define _SORTHER_

#include <algorithm>
template <typename T, typename T2>
class Sorter {
private:
    void static Heapify(T2 arr, int n, int id, bool ascending) {
        int pos = id;
        int l = (id << 1) | 1;
        int r = l + 1;
        if (l < n && (ascending ? (arr[pos] < arr[l]) : (arr[l] < arr[pos]))) {
            pos = l;
        }
        if (r < n && (ascending ? (arr[pos] < arr[r]) : (arr[r] < arr[pos]))) {
            pos = r;
        }
        if (pos != id) {
            std::swap(arr[id], arr[pos]);
            Heapify(arr, n, pos, ascending);
        }
    }
    void static merge(T2 arr, T2 t, int l, int r, int mid, bool ascending) {
        int pos = 0;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if ((ascending ? (arr[i] < arr[j]) : (arr[j] < arr[i]))) {
                t[pos++] = arr[i++];
            } else {
                t[pos++] = arr[j++];
            }
        }
        while (i <= mid) {
            t[pos++] = arr[i++];
        }
        while (j <= r) {
            t[pos++] = arr[j++];
        }
        for (int i = 0; i < pos; i++) {
            arr[l + i] = t[i];
        }
    }

public:

    void static InsertionSorter(T2 arr, int size, bool ascending = true) {
        for (int j = 1; j < (int)size; j++) {
            T key = arr[j];
            int i = j - 1;
            while (i >= 0 && (ascending ? (key < arr[i]) : (arr[i] < key))) {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = key;
        }
    }

    void static shellSort(T2 arr, int l, int r, bool ascending = true) {
        for (int step = (r - l + 1) >> 1; step > 0; step >>= 1) {
            for (int i = 0; i < step; i++) {
                for (int j = l + i + step; j <= r; j += step) {
                    T temp = arr[j];
                    int k = j - step;
                    while (k >= l + i &&
                           (ascending ? (temp < arr[k]) : (arr[k] < temp))) {
                        arr[k + step] = arr[k];
                        k -= step;
                    }
                    arr[k + step] = temp;
                }
            }
        }
    }

    void static quickSort(T2 arr, int left, int right, bool ascending = true) {
        int i = left, j = right;
        T mid = arr[(i + j) >> 1];
        while (i <= j) {
            if (ascending) {
                while (arr[i] < mid) i++;
                while (mid < arr[j]) j--;
            } else {
                while (mid < arr[i]) i++;
                while (arr[j] < mid) j--;
            }
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        if (i < right) quickSort(arr, i, right, ascending);
        if (left < j) quickSort(arr, left, j, ascending);
    }

    void static BullbleSort(T2 arr, int len, bool ascending = true) {
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if ((ascending ? (arr[j + 1] < arr[j])
                               : (arr[j] < arr[j + 1]))) {
                    std::swap(arr[j + 1], arr[j]);
                }
            }
        }
    }

    void static SelectSort(T2 arr, int l, int r, bool ascending = true) {
        for (int i = l; i < r; i++) {
            int pos = i;
            for (int j = i + 1; j <= r; j++) {
                if ((ascending ? (arr[j] < arr[pos]) : (arr[pos] < arr[j]))) {
                    pos = j;
                }
            }
            std::swap(arr[i], arr[pos]);
        }
    }

    void static HeapSort(T2 arr, int len, bool ascending = true) {
        for (int i = len - 1; i >= 0; i--) {
            Heapify(arr, len, i, ascending);
        }
        for (int i = len - 1; i >= 0; i--) {
            std::swap(arr[0], arr[i]);
            Heapify(arr, i, 0, ascending);
        }
    }

    void static MergeSort(T2 arr, T2 t, int l, int r, bool ascending = true) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        MergeSort(arr, t, l, mid, ascending);
        MergeSort(arr, t, mid + 1, r, ascending);
        merge(arr, t, l, r, mid, ascending);
    }

    void static RadixSort(T2 arr, int len, bool ascending = true) {
        std::vector<T> temp(len);
        int maxRadix = 1;
        for (int i = 0; i < len; i++) {
            while ((arr[i] / maxRadix) > 9) {
            	maxRadix *= 10;
			}
        }

        int cnt[10];
        for (int i = 0; i < 10; i++) {
            cnt[i] = 0;
        }

        for (int radix = 1; radix <= maxRadix; radix *= 10) {
            for (int i = 0; i < 10; i++) {
                cnt[i] = 0;
            }

            for (int i = 0; i < len; i++) {
                cnt[(arr[i] / radix) % 10]++;
            }
            if (ascending) {
                for (int i = 1; i < 10; i++) {
                    cnt[i] += cnt[i - 1];
                }
            } else {
                for (int i = 8; i >= 0; i--) {
                    cnt[i] += cnt[i + 1];
                }
            }

            for (int i = len - 1; i >= 0; i--) {
                int pos = (arr[i] / radix) % 10;
                temp[cnt[pos] - 1] = arr[i];
                cnt[pos]--;
            }
			
            for (int i = 0; i < len; i++) {
                arr[i] = temp[i];
            }
        }
    }
};

#endif
