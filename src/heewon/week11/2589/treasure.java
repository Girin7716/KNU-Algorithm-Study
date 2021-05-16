//https://www.youtube.com/watch?v=yQ7o1Y7X_Rg 보고 BFS 코딩


import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class treasure {
	
	static int[][] dir= {{-1,0},{1,0},{0,-1},{0,1}};
	
	static class Point{
		Point(int r, int c, int d) {
			row = r; col=c; dist=d;
		}
		int row, col, dist;
	}
	
	static int bfs(char matrix[][], int row, int col, int sRow, int sCol) {
		boolean[][] visited=new boolean[row][col];
		Queue<Point> myqueue=new LinkedList<>();
		visited[sRow][sCol]=true;
		myqueue.add(new Point(sRow, sCol, 0));
		
		int i;
		
		while(!myqueue.isEmpty()) {
			Point curr=myqueue.remove();
			
			for(i=0; i<4; i++) {
				int nr=curr.row+dir[i][0], nc=curr.col+dir[i][1];
				if(nr<0 || nr>row-1 || nc<0 || nc>col-1) continue;
				if(visited[nr][nc]) continue;
				if(matrix[nr][nc]=='W') continue;
				visited[nr][nc]=true;
				myqueue.add(new Point(nr, nc, curr.dist+1));	
			}
			
			if(myqueue.isEmpty()) {
				return curr.dist;
			}
		}
		
		return 0;
	}

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int row, col;
		int dist=0; int tmp;
		row=sc.nextInt();
		col=sc.nextInt();
		
		char[][] matrix= new char[row][col];
		
		for(int i=0; i<row; i++) {
			matrix[i]=sc.next().toCharArray();
		}
		
		for (int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				if (matrix[i][j]=='L'){
					tmp=bfs(matrix, row, col, i, j);
					if(dist<tmp)
						dist=tmp;	
				}
			}
		}
		
		System.out.println(dist);
	}

}
