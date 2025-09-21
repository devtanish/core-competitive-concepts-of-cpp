// Implement a matrix multiplication program

#include<iostream>
#include<vector>
#include<string>
#include<variant>

std::variant<std::vector<std::vector<int>>, std::string> multMetrix(std::vector<std::vector<int>> M1, std::vector<std::vector<int>> M2){
    if(M1.empty() || M2.empty() || M1[0].empty() || M2[0].empty()){
        return "Empty matrix provided";
    }
    
    if(M1[0].size() != M2.size()){
        return "not a valid matrix for multiplication";
    } else {
        int rows = M1.size();
        int cols = M2[0].size();
        std::vector<std::vector<int>> ans(rows, std::vector<int>(cols, 0));
        
        for(int m=0 ; m<rows ; m++){
            for(int n=0 ; n<cols ; n++){
                for(int p=0 ; p<M1[0].size() ; p++){ 
                    ans[m][n] += M1[m][p] * M2[p][n];
                }
            }
        }

        return ans;
    }
}

void print_matrix(std::vector<std::vector<int>> matrix){
    for(int m=0 ; m<matrix.size() ; m++){
        for(int n=0 ; n<matrix[0].size() ; n++){
            std::cout<<matrix[m][n]<<"  ";
        }
        std::cout<<std::endl;
    }
}

auto main() -> int {
    // ( m * n ) = ( 3 * 2 )
    std::vector<std::vector<int>> M1{{
        {1, 2},
        {3, 4},
        {5, 6},
    }};
    
    // ( n * p ) = ( 2 * 3 )
    std::vector<std::vector<int>> M2{{
        {1, 2, 5},
        {3, 4, 6},
    }};

    auto ans = multMetrix(M1, M2);

    if (std::holds_alternative<std::vector<std::vector<int>>>(ans)) {
        const auto& result_matrix = std::get<std::vector<std::vector<int>>>(ans);
        print_matrix(result_matrix);
    } else {
        const auto& error_msg = std::get<std::string>(ans);  // Fixed: get string
        std::cout << error_msg << std::endl;
    }

    return 0;
}