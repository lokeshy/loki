#pragma once
#include <vector>
using namespace std;
#include <algorithm> 

namespace MinPathSum {
	class Solution {
	public:
		int minPathSum(vector<vector<int>>& grid) {
			int row = grid.size();
			int col = 0;
			if (row == 0) {
				return 0;
			}else {
				col = grid.at(0).size();
			}

			int **outGrid = new int*[row];
			for (int i = 0; i < row; ++i) {
				outGrid[i] = new int[col];
			}

			int i = 0;
			int j = 0;
			for (i = 0; i < grid.size(); ++i) {
				for (j = 0; j < grid.at(i).size(); ++j) {
					if (i == 0 && j == 0) {
						/// first element
						outGrid[0][0] = grid.at(i).at(j);
					}
					else if(i == 0 && j > 0) {
							outGrid[i][j] = outGrid[i][j-1] + grid.at(i).at(j);
					}else if (i > 0 && j == 0) {
							outGrid[i][j] = outGrid[i-1][j] + grid.at(i).at(j);
					}else{
							outGrid[i][j] = min(outGrid[i - 1][j], outGrid[i][j-1]) + grid.at(i).at(j);
					}
					
				}
			}

			return outGrid[row-1][col-1];
		}
	};
}
