import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.Stack;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), (" "));
		int N=Integer.parseInt(st.nextToken());
		int K=Integer.parseInt(st.nextToken());
		int count=0;
		
		String tmp=br.readLine();

		Stack<Integer> stack = new Stack<>();
		stack.push(tmp.charAt(0) - '0');
		
		
		for (int i=1 ;i <N; i++) {
			while(count!=K && !stack.isEmpty() && stack.peek() < (tmp.charAt(i)-'0')) {
				stack.pop();
				count++;
			}
			stack.push(tmp.charAt(i) - '0');
		}
		
		while(count != K) {
			stack.pop();
			count++;
		}
		for(int i=0; i<N-K; i++) {
			System.out.print(stack.get(i));
		}
		
	}
}
