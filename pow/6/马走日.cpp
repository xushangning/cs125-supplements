/**
 * Idea: Warnsdorff's rule
 *
 * "The knight is moved so that it always proceeds to the square from which the
 * knight will have the fewest onward moves."
 *
 * Example: standing at (0, 0), our possible next positions are (2, 1), (1, 2).
 * For each possible position, we shall suppose we've moved to that position,
 * and count the number of next possible positions.
 *
 * See https://en.wikipedia.org/wiki/Knight%27s_tour#Warnsdorff's_rule
 */

#include <iostream>
#include <queue>

using namespace std;

constexpr int N_DIRECTIONS = 8;
constexpr int offset[N_DIRECTIONS][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {2, -1}, {1, -2}
};

/**
 * board[i][j] == k means the knight moves to (i, j) at step k.
 * If board[i][j] == 0, then we haven't stepped on (i, j).
 */
int board[10][10];

/**
 * n for board size, max_steps == n * n
 * curr_steps records how many steps the knight has walked, using the function
 * step(x, y).
 */
int n, max_steps, curr_steps;

struct Pos
{
    // i is an index into the offset array.
    // moves is the number of next possible positions
    int i, moves;
};

bool cmp(const Pos &l, const Pos &r) { return l.moves > r.moves; }

inline bool valid_coordinate(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

/**
 * Standing at (x, y), count the number of possible positions for the next step.
 */
inline int count_moves(int x, int y)
{
    int n_moves = 0, next_x, next_y;
    for (auto &p : offset) {
        next_x = x + p[0];
        next_y = y + p[1];
        n_moves += valid_coordinate(next_x, next_y) && board[next_x][next_y] == 0;
    }
    return n_moves;
}

/**
 * Move to (x, y) and explore next steps.
 */
bool step(int x, int y)
{
    board[x][y] = ++curr_steps;
    if (curr_steps == max_steps)
        return true;

    priority_queue<Pos, vector<Pos>, decltype(cmp) *> q(cmp);
    // count the number of next possible positions for each direction
    int n_moves, next_x, next_y;
    for (int i = 0; i < N_DIRECTIONS; ++i) {
        next_x = x + offset[i][0];
        next_y = y + offset[i][1];
        if (valid_coordinate(next_x, next_y) && board[next_x][next_y] == 0) {
            n_moves = count_moves(next_x, next_y);
            if (n_moves || curr_steps + 1 == max_steps)
                q.push({i, n_moves});
        }
    }
    // How to select the next position with minimum next possible positions?
    // 1. Sorting
    // 2. Priority queue, where the move with minimum next possible positions
    //  is always at the front.
    while (!q.empty()) {
        const Pos &my_pos = q.top();
        // walk one step
        if (step(x + offset[my_pos.i][0], y + offset[my_pos.i][1]))
            return true;
        q.pop();
    }

    --curr_steps;
    board[x][y] = 0;
    return false;
}

int main()
{
    int x, y;
    cin >> n >> x >> y;
    max_steps = n * n;
    if (step(x - 1, y - 1))
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout.width(4);
                cout << board[i][j];
            }
            cout << '\n';
        }
    else
        cout << "None\n";
    return 0;
}
