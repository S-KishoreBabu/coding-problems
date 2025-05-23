bool canMakeBouquets(int* bloomDay, int size, int m, int k, int day) {
    int count = 0, bouquets = 0;
    for (int i = 0; i < size; i++) {
        if (bloomDay[i] <= day) {
            count++;
            if (count == k) {
                bouquets++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return bouquets >= m;
}

int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    if ((long long)m * k > bloomDaySize) return -1;
    
    int left = INT_MAX, right = INT_MIN;
    for (int i = 0; i < bloomDaySize; i++) {
        if (bloomDay[i] < left) left = bloomDay[i];
        if (bloomDay[i] > right) right = bloomDay[i];
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canMakeBouquets(bloomDay, bloomDaySize, m, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
