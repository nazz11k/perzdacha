#include "liba.h"

void generator(int** matrix, int m){
    srand(time(0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j]=(rand()%691)-190;
        }
    }
    matrix_outer(matrix, m, "Generated matrix: ");
}

void founder(int** matrix, int m){
    int min_sum=100;
    int min_row=0;
    int min_num=0;
    cout<<"List of negative elements of main diagonal: "<<endl;
    for (int j = 0; j < m; ++j) {
        if(matrix[j][j]<0){
            cout<<j+1<<" - "<<matrix[j][j]<<endl;
            for (int i = 0; i < m; ++i) {
                if(sum_f(matrix[i][j])<min_sum){
                    min_sum=sum_f(matrix[i][j]);
                    min_row=i;
                    min_num=matrix[i][j];
                }
            }
        }
    }
    cout<<endl<<"Our original element is "<<min_num<<" in row "<<min_row+1<<" with sum "<<min_sum<<endl;
    swapper(matrix, m, min_row);
    matrix_outer(matrix, m, "Swapped matrix: ");
}

void swapper(int** matrix, int m, int min_row){
    int* tmp;
    tmp=matrix[min_row];
    matrix[min_row]=matrix[m-1];
    matrix[m-1]=tmp;
}

int sum_f(int number){
    int number1=abs(number);
    int sum=0;
    while(number1){
        sum+=number1%10;
        number1 /=10;
    }
    return sum;
}

void stringer(int** matrix, int m, string* diagonals){
    for (int i = 0; i < m; ++i) {
        diagonals[0]+=to_string(matrix[i][i]);
        diagonals[1]+=to_string(matrix[i][m-i-1]);
        diagonals[0]+=" ";
        diagonals[1]+=" ";
    }
    outer(diagonals, "Strings: ");
}

void separator(string* diagonals){
    for (int i = 0; i < 2; ++i) {
        diagonals[i].push_back(' ');
        string positive="", negative="";
        int pos=0;
        while(pos<diagonals[i].length()-1){
            string cur_number=diagonals[i].substr(pos, (diagonals[i].find(" ", pos)-pos));
            pos=diagonals[i].find(" ", pos)+1;
            if(stoi(cur_number)>0){
                positive+=cur_number+" ";
            }
            else{
                negative+=cur_number+" ";
            }
        }
        string row=negative+" "+positive;
        diagonals[i]=row;
    }
    outer(diagonals, "Separated strings: ");
}

void matrix_outer(int** matrix, int m, string name){
    cout<<endl<<name<<endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<setw(5)<<matrix[i][j];
        }
    cout<<endl;
    }
}

void outer(string* lines, string name){
    cout<<endl<<name<<endl;
    for (int i = 0; i < 2; ++i) {
        cout<<lines[i]<<endl;
    }
}