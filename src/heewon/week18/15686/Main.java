import java.util.*;

public class Main {

	static int M;
	static ArrayList<int[]> home;
	static ArrayList<int[]> chicken;
	static int result=99999;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();
		M=sc.nextInt();
		home =new ArrayList<>();
		chicken = new ArrayList<>();
		int city[][]=new int[N][N];
		int i, j;
		for (i=0; i<N; i++) {
			for(j=0; j<N; j++) {
				city[i][j]=sc.nextInt();
				if(city[i][j]==1)
					home.add(new int[] {i, j});
				else if (city[i][j]==2)
					chicken.add(new int[] {i, j});
			}
		}
		
		dis=new int[M];
		dfs(0,0);
		
		System.out.println(result);
	}
	static int[] dis;
	private static void dfs(int index, int start) {
		if(index==M) {
			int sum=0;
			for(int i=0; i<home.size(); i++) {
				int min=99999;
				for(int j=0; j<dis.length; j++) {
					int tmp=Math.abs(chicken.get(dis[j])[0]-home.get(i)[0])+Math.abs(chicken.get(dis[j])[1]-home.get(i)[1]);
					
					min=Math.min(min, tmp);
				}
				sum+=min;
			}
			result=Math.min(sum, result);
			return;
		}
		
		for(int i=start; i<chicken.size(); i++) {
			dis[index]=i;
			dfs(index+1, i+1);
		}
	}

}
