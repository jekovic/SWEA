#include <iostream>
#include <climits> 

using namespace std;

struct glid_type {
    int r, c, cnt;
};

int S, N, Map[100][100], Cost[101], AnsCnt;
int Answer[10000][3];


int countDamage(int row, int col, int size) {
    int cnt = 0;
    for (int i = row; i < row + size; i++)
        for (int j = col; j < col + size; j++)
            if (Map[i][j] == 1)
                cnt++;
    return cnt;
}

glid_type findOptimal(int row, int col, int size, int glidSize) {
    int maxCnt = 0, maxR = -1, maxC = -1;
    for (int i = row; i <= row + size - glidSize; i++) {
        for (int j = col; j <= col + size - glidSize; j++) {
            int cnt = countDamage(i, j, glidSize);
            if (cnt > maxCnt) {
                maxCnt = cnt;
                maxR = i;
                maxC = j;
            }
        }
    }
    return { maxR, maxC, maxCnt };
}

void setMark(int row, int col, int size, int curValue, int newValue) {
    for (int i = row; i < row + size; i++)
        for (int j = col; j < col + size; j++)
            if (Map[i][j] == curValue)
                Map[i][j] = newValue;
}

int solve(int row, int col, int size, int glidSize, bool first) {
    int sumCost = 0, cost1, cost2;
    while (glidSize > 1) {
        glid_type glid1 = findOptimal(row, col, size, glidSize);
        if (glid1.cnt == 0) break;

        cost1 = Cost[glidSize];
        cost2 = 0;
        if (glidSize > 2) {
            glid_type glid2 = findOptimal(glid1.r, glid1.c, glidSize, glidSize - 1);
            cost2 = Cost[glidSize - 1];
            setMark(glid2.r, glid2.c, glidSize - 1, 1, 2);

            glid_type glid3;
            do {
                glid3 = findOptimal(glid1.r, glid1.c, glidSize, 2);
                if (glid3.cnt > 1) {
                    cost2 += Cost[2];
                    setMark(glid3.r, glid3.c, 2, 1, 2);

                }
            } while (glid3.cnt > 1);
        }

        cost2 += Cost[1] * countDamage(glid1.r, glid1.c, glidSize);
        setMark(glid1.r, glid1.c, glidSize, 2, 1);

        int cost3 = INT_MAX, cost4 = INT_MAX, newGlidSize1, newGlidSize2;
        if (first && glidSize > 6) {
            newGlidSize1 = (glidSize + 1) / 2;
            cost3 = solve(row, col, size, newGlidSize1, false);
            newGlidSize2 = (glidSize + 1) / 4;
            cost4 = solve(row, col, size, newGlidSize2, false);
        }
        if (cost1 <= cost2 && cost1 <= cost3 && cost1 <= cost4) {
            setMark(glid1.r, glid1.c, glidSize, 1, first ? 3 : 4);
            sumCost += cost1;
            if (first) {
                Answer[AnsCnt][0] = glid1.r + 1;
                Answer[AnsCnt][1] = glid1.c + 1;
                Answer[AnsCnt++][2] = glidSize;
            }
        }
        else if (cost2 <= cost1 && cost2 <= cost3 && cost2 <= cost4)
            --glidSize;
        else if (cost3 <= cost1 && cost3 <= cost2 && cost3 <= cost4)
            glidSize = newGlidSize1;
        else
            glidSize = newGlidSize2;
    }

    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            if (Map[i][j] == 1) {
                sumCost += Cost[1];
                if (first) {
                    Answer[AnsCnt][0] = i + 1;
                    Answer[AnsCnt][1] = j + 1;
                    Answer[AnsCnt++][2] = 1;
                }
            }
        }
    }

    if (!first) setMark(row, col, size, 4, 1);
    return sumCost;
}


int main(int argc, char** argv) {
    for (int i = 1; i <= 100; i++)
        Cost[i] = (int)(i * i / 2.0 + 2 * i / 3.0 + 1.0);
    int tcCnt, r, c;
    cin >> tcCnt;
    for (int t = 1; t <= tcCnt; t++) {
        cin >> S >> N;
        for (int i = 0; i < S; i++)
            for (int j = 0; j < S; j++)
                Map[i][j] = 0;

        for (int i = 0; i < N; i++) {
            cin >> r >> c;
            Map[r - 1][c - 1] = 1;
        }
        AnsCnt = 0;
        solve(0, 0, S, S, true);
        cout << "#" << t << ' ' << AnsCnt;
        for (int i = 0; i < AnsCnt; ++i)
            cout << ' ' << Answer[i][0] << ' ' << Answer[i][1] << ' ' << Answer[i][2];
        cout << '\n';
    }

    return 0;
}