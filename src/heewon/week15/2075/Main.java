import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N=Integer.parseInt(br.readLine());
		
		StringTokenizer st;
		PriorityQueue<Integer> queue=new PriorityQueue<Integer>(Collections.reverseOrder());
		for (int i=0; i<N; i++) {
			st=new StringTokenizer(br.readLine(), " ");
			for(int j=0; j<N; j++) {
				queue.add(Integer.valueOf(st.nextToken()));
			}
		}
		
		int order=1;
		while(!queue.isEmpty()) {
			if(order==N) {
				System.out.println(queue.poll());
				return;
			}
			else {
				queue.poll();
				order++;
			}
			
		}
		
		
	}

}
