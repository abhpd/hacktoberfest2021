template<class T>
class matrix{
    size_t ROW,COL;
    vector<vector<T>> mat;
public:
    matrix(size_t N, size_t M, int populate = 0){
        this->ROW = N;
        this->COL = M;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,populate));
    }
    matrix(size_t N, int populate = 0){
        this->ROW = N;
        this->COL = N;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,populate));
    }
    void __init(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cin  >> this->mat[i][j];
            }
        }
    }
    void __display(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cout << this->mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
    matrix<T> operator*(const matrix &rhs)const{
        if(this->COL != rhs.ROW){
            throw "MATRIX MULTIPLICATION CANNOT HAPPEN WITH THE GIVEN MATRICES"
        }
        matrix<T> result(this->ROW,rhs.COL);
        for(int _i = 0; _i < this->ROW; _i++){
            for(int _j = 0; _j < rhs.COL; _j++){
                result[_i][_j] = 0;
                for(int _k = 0; _k < this->COL; ++_k){
                    result[_i][_j]+=(this->mat[_i][_k]*rhs.mat[_k][_j]);
                }
            }
        }
        return result;
    }
    matrix<T> power(int n){
        if(n == 0)return matrix<T>(this->ROW, this->COL,1);
        if(n == 1)return *this;
        matrix p = power(n/2);
        p = p*p;
        if(n%2)p = p*(*this);
        return p;
    }
};