#include <string.h>

class Map {
    int row;
    int col;
    int** map;
public:
    Map(const int h, const int w):row(h), col(w) {
        map = new int* [h];
        for(int i= 0; i < h; i++) {
            map[i] = new int [w];
            memset(map[i], 0, sizeof(int)*h);
        }
    }

    /*~Map() {
        for(int i = 0; i < row; i++){
                delete[] map[i];
                map[i] = nullptr;
        }
        delete[] map;
        map = nullptr;
    }
   */
    int** initialMap() {
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                map[row/2][col/2] = 3;
                if(i == 0 && j == 0 || i == 20 && j == 20 || i == 20 && j == 0 || i == 0 && j == 20) {
				    map[i][j] = 2;
			    } else if (i == 0 or i == 20 or j == 0 or j == 20) {
				    map[i][j] = 1;
			    } else {
                    map[i][j] = 0;
                }
            }
        }  
        return map; 
    }

};