import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static class Point{
		Point(int r, int c, int h, int d) {
			row = r; col=c; count=h; dist=d;
		}
		int row, col, count, dist;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int K=Integer.parseInt(br.readLine());
		StringTokenizer st=new StringTokenizer(br.readLine()," ");
		int W=Integer.valueOf(st.nextToken());
		int H=Integer.valueOf(st.nextToken());
		
		int[][] Board=new int[H][W];
		int result=-1;
		
		for (int i=0; i<H; i++) {
			st=new StringTokenizer(br.readLine()," ");
			for(int j=0; j<W; j++) {
				Board[i][j]=Integer.valueOf(st.nextToken());
			}
		}
		
		
		boolean[][][] visited=new boolean[K+1][H][W];
		int[][] D= {{-1,0},{1,0},{0,-1},{0,1},{-2,1},{-1,2},{1,2},{2,1},{-2,-1},
				{-1,-2},{1,-2},{2,-1}};
		Queue<Point> myqueue=new LinkedList<>();
		visited[0][0][0]=true;
		myqueue.add(new Point(0, 0, 0, 0));
		
		while(!myqueue.isEmpty()) {
			Point curr=myqueue.remove();
			if(curr.row==H-1 && curr.col==W-1) {
				result=curr.dist;
				break;
			}
			
			
			for(int i=0; i<12; i++) {
				int nr=curr.row+D[i][0], nc=curr.col+D[i][1];
				if(nr<0||nr>H-1||nc<0||nc>W-1) continue;
				if(visited[curr.count][nr][nc])continue;
				if(Board[nr][nc]==1) continue;				
				switch((i<4)? 0 : 1) {
				case 0:
					if(!visited[curr.count][nr][nc]) {
						visited[curr.count][nr][nc]=true;
						myqueue.add(new Point(nr, nc, curr.count, curr.dist+1));
					}
					break;
				case 1:
					if(curr.count<K && !visited[curr.count+1][nr][nc]) {
						visited[curr.count+1][nr][nc]=true;
						myqueue.add(new Point(nr, nc, curr.count+1, curr.dist+1));
					}
					break;
				}
			}
			
		}
		
		System.out.println(result);
			
	}

}
