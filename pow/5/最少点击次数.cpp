// This solution is provided by Junqi Xie.
//
// The idea of the solution is very straightforward:
//
// If we fix the 1st row, starting from the 2nd row, for every extinguished light
//   in the previous row, we have to click the corresponding position in the next
//   row to turn it on. After the operation is over, we can test whether all the
//   lights in the last row are on to verify whether we've found a solution or not.
//
// In light of this idea, we can try all the possibilities of the 1st row, and find
//   the minimal clicking time among all the possible solutions.
//

#include <iostream>

using namespace std;

// encapsulate the action of fliping into a function, since we'll be using it many
// times in main()
void flip(bool lights[5][5], int i, int j)
{
    // bool lights[5][5]: the matrix containing the situation of all the lights
    // int i, int j: the index of the light we're dealing with

    lights[i][j] = !lights[i][j]; // switch the light itself
    // If its neighboring lights exist (the index is in the range of [0, 5)),
    //   switch them as well.
    if (j - 1 >= 0)
        lights[i][j - 1] = !lights[i][j - 1];
    if (i - 1 >= 0)
        lights[i - 1][j] = !lights[i - 1][j];
    if (i + 1 < 5)
        lights[i + 1][j] = !lights[i + 1][j];
    if (j + 1 < 5)
        lights[i][j + 1] = !lights[i][j + 1];
}


int main()
{
    bool lights[5][5] = { };
    // read the matrix row by row
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
            lights[i][j] = static_cast<int>(cin.get() - '0');
        cin.get();   // eat the '\n' at the end of the line
    }
    
    // Assume that the puzzle is solvable, we can use the macros of the largest
    //   int to indicate "not finding solutions yet".
    int min_flip = INT32_MAX;

    // try all the possibilities of the 1st row
    //
    // As fliping the same position twice is equivalent to not fliping at all,
    //   we use nested iterations to simulate the process of enumeration.
    // Among these iterations, a, b, c, d, e stands for the 1st, 2nd, ..., 5th
    //   column respectively, while 0 stands for "not flipped" and 1 stands for
    //   "flipped". Therefore, the current clicking time is a + b + c + d + e.
    //
    // The iterations can also be written in the form of recursions (backtracking).
    //
    for (int a = 0; a < 2; ++a)
    {
        for (int b = 0; b < 2; ++b)
        {
            for (int c = 0; c < 2; ++c)
            {
                for (int d = 0; d < 2; ++d)
                {
                    for (int e = 0; e < 2; ++e)
                    {
                        // We don't want to affect the original matrix when testing,
                        //   so it's necessary to create a copy of the original.
                        bool lights_copy[5][5] = { };
                        for (int i = 0; i < 5; ++i)
                            for (int j = 0; j < 5; ++j)
                                lights_copy[i][j] = lights[i][j];
                        
                        // calculate the rest of the matrix based on the algorithm
                        //   presented at the beginning
                        int flip_time = a + b + c + d + e;
                        for (int i = 1; i < 5; ++i)
                            for (int j = 0; j < 5; ++j)
                                if (!lights_copy[i - 1][j])
                                {
                                    flip(lights_copy, i, j);
                                    ++flip_time;
                                }
                        
                        // test if the result obtained is a solution
                        bool has_found = true;
                        for (int j = 0; j < 5; ++j)
                            has_found &= lights_copy[4][j];
                        
                        // update the minimal clicking time if a solution is obtained
                        if (has_found)
                            min_flip = min(flip_time, min_flip);

                        flip(lights, 0, 4);
                    }
                    flip(lights, 0, 3);
                }
                flip(lights, 0, 2);
            }
            flip(lights, 0, 1);
        }
        flip(lights, 0, 0);
    }

    cout << min_flip << endl;
    return 0;
}
