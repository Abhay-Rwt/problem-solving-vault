class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> mat(query_row+1);

        mat[0].push_back(poured);

        for(int i=1; i<=query_row; i++){
            vector<double> temp(i+1);

            for(int j=0; j<i+1; j++){
                double l=0,r=0;
                if((j-1 >= 0) && ((mat[i-1][j-1] - 1 )>= 0)){
                    l = (mat[i-1][j-1] - 1) / 2.0;
                }
                if((j < i) && ((mat[i-1][j] - 1) >= 0)){
                    r = (mat[i-1][j] - 1) / 2.0;
                }

                temp[j] = l + r;
            }

            mat[i] = temp;
        }

        return min(1.0, mat[query_row][query_glass]);
    }
};