// "An image is represented by an m x n integer grid image where image[i][j]
// represents the pixel value of the image.
// You are also given three integers sr , sc and color . You should perform
// a flood fill on the image starting from the pixel image[sr][sc] .
// Return the modified image after performing the flood fill"
#include<iostream>
using namespace std;
//Function to display matrix
void display(int row,int col,int a[][100]);
//function to floodfill 
void floodfill(int r,int c,int color,int ogcolor,int row,int col,int a[][100]);
int main()
{
    int m {},n {},img[100][100];
    cout<<"Enter the size image";
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter the image["<<i<<"]["<<j<<"] values";
            cin>>img[i][j];
        }
        cout<<endl;
    }
    display(m,n,img);
    int r {},c {},color {},temp {};
    cout<<"Enter the row and column index to floodfill";
    cin>>r>>c;
    cout<<"Enter the color to floodfill";
    cin>>color;
    int ogcolor=img[r][c];
    floodfill(r,c,color,ogcolor,m,n,img);
    display(m,n,img);

    return 0;
}
void display(int row,int col,int a[][100])
{
    cout<<"Image  is:"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void floodfill(int r,int c,int color,int ogcolor,int row,int col,int a[][100])
{
    // Check boundaries and whether the current pixel has the original color
    if (r < 0 || r >= row || c < 0 || c >= col || a[r][c] != ogcolor)
    {
        return;
    }

    // Update the color of the current pixel
    a[r][c] = color;
    
    // Recursively call floodfill for neighboring pixels
    floodfill(r + 1, c, color, ogcolor, row, col, a); // Down
    floodfill(r - 1, c, color, ogcolor, row, col, a); // Up
    floodfill(r, c + 1, color, ogcolor, row, col, a); // Right
    floodfill(r, c - 1, color, ogcolor, row, col, a); // Left

}
