#include<iostream>
#include<vector> 

using namespace std ;

bool isSafe ( int i , int j , int row , int column , int arr [3][3] , vector < vector < bool > > &v )
{
        if ( ( ( i >= 0 && i < row  ) && ( j >= 0 && j < column )) && ( arr [ i ] [ j ] == 1 ) && ( v [ i ] [ j ] == false ) ) {
            return true ;
        }
        else {
            return false ;
        }
}

void solveMaze ( int arr [ 3 ] [ 3 ] , int row , int i , int j , vector <vector < bool > > &v , vector < string > &path , string output , int column )
{
        // base case 
        if ( i == row - 1 && j == column - 1 )
        {
            // answer found 

            path . push_back ( output ) ; 
            return ; 
        }

        // down -- > i + 1 , j
        if ( isSafe ( i + 1 , j , row , column , arr , v ) ){

            v [ i + 1 ] [ j ] = true ;
            solveMaze ( arr , row , i + 1 , j , v , path , output + "d" , column ) ;
            // back tracking 

            v [ i + 1 ] [ j ] = false ;
        }
        // left -- > i , j - 1
        if (isSafe(i, j - 1, row, column, arr, v)){
            v[i][j - 1] = true;
            solveMaze( arr , row , i , j - 1 , v , path , output + "l" , column ) ;
            v[i][j - 1] = false;
        }

        // right -- > i , j + 1 
        if (isSafe(i, j + 1, row, column, arr, v)){
            v[i][j + 1] = true;
            solveMaze(arr, row, i, j + 1, v, path, output + "r", column);
            v[i][j + 1] = false;
        }

        // up -- > i - 1 , j
        if (isSafe(i - 1, j, row, column, arr, v)){
            v[i - 1][j] = true;
            solveMaze(arr, row, i - 1, j, v, path, output + "u", column);
            v[i - 1][j] = false;
        }
}

int main () 
{
    int maze [ 3 ] [ 3 ]  =  { { 1 , 0 , 0 } , { 1 , 1 , 0  } , { 1 , 1 , 1 } } ;

    int row = 3 ;
    int column = 3 ;

    vector < vector < bool > > v ( row , vector < bool > ( column , false )) ; // declared a 2 - d vector 

    v [ 0 ] [ 0 ] = true ;
    vector < string > path ;
    string output = " " ;

    solveMaze ( maze , row , 0 , 0 , v , path , output , column )  ;

    cout << " printing the results " << endl ;
    for ( auto i : path ) {
        cout << i << " "  ;
    }
    cout << endl ;

    return 0 ;
}
