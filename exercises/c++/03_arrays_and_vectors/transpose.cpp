#include <array>
#include <iostream>

//transpose square matrix in place
template <std::size_t SIZE>
void transpose_square( std::array<double, SIZE> &matrix, const std::size_t N, const std::size_t M);

//transpose any matrix
template <std::size_t SIZE>
void transpose( const std::array<double, SIZE> &matrix,std::array<double, SIZE> &tr, const std::size_t N, const std::size_t M);

//another version of transpose
template <std::size_t SIZE>
void  transpose_2( const std::array<double, SIZE> &matrix, std::array<double, SIZE> &tr, const std::size_t N, const std::size_t M);

//print a matrix
template <std::size_t SIZE>
void print_matrix( const std::array<double, SIZE> &matix, const std::size_t N, const std::size_t M);

int main(){

    const std::size_t N = 4;
    const std::size_t M = 10;
    std::array<double, M*N> mat{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    std::array<double, M*N> tr;
    print_matrix(mat, N, M);
    std::cout << std::endl;
    //if square mat
    //transpose_square(mat, N, M);
    //print_matrix(mat, M, N);
    //otherwise
    //transpose_2(mat, tr, N, M);
    transpose(mat, tr, N, M);
    print_matrix(tr, M, N);
}


template <std::size_t SIZE>
void transpose_square( std::array<double, SIZE> &matrix, const std::size_t N, const std::size_t M){

    double temp;
    for (std::size_t i = 0; i < N; i++){
        for (std::size_t j = i; j < M; j++){

            temp = matrix[M*i + j];
            matrix[M*i + j] = matrix[M*j + i];
            matrix[M*j + i] = temp;
        }
    }
}
template <std::size_t SIZE>
void print_matrix( const std::array<double, SIZE> &matrix, const std::size_t N, const std::size_t M){

    for (std::size_t i = 0; i < N; i++){
        for (std::size_t j = 0; j < M; j++)
            std::cout << matrix[M*i + j] << " ";
        std::cout << std::endl;
    }
}
template <std::size_t SIZE>
void transpose( const std::array<double, SIZE> &matrix,std::array<double, SIZE> &tr, const std::size_t N, const std::size_t M){

    for (std::size_t i = 0; i < SIZE; i++)
        tr[i] = matrix[(i%N)*M + i/N];
    
}
template <std::size_t SIZE>
void transpose_2( const std::array<double, SIZE> &matrix, std::array<double, SIZE> &tr, const std::size_t N, const std::size_t M){

    for (std::size_t i = 0; i < SIZE; i++)
        tr[N*(i%M) + (i/M)] = matrix[i];
}
