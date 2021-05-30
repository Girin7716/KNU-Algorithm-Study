import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

	static void palindrome(int N) {

		String s=Integer.toString(N);
		
		if(s.charAt(0)!=s.charAt(s.length()-1))
			return;
		
		StringBuffer rsb= new StringBuffer();
		rsb.append(s);
		rsb=rsb.reverse();
		String s2=rsb.toString();
		
		
		if(s2.equals(s)) {
			System.out.println(s);
		}

	}
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine()," ");
		int N1=Integer.valueOf(st.nextToken());
		int N2=Integer.valueOf(st.nextToken());
		int i, j;
		boolean[] prime=new boolean[10000001];
		
		prime[0]=prime[1]=prime[4]=false;
		prime[2]=prime[3]=true;
		
		for (i=5; i<=10000000; i++)
			prime[i]=true;
				
		for(i=2; i*i<=10000000; i++)
			for(j=i*i; j<=10000000; j+=i) {
				prime[j]=false;
			}
					
		//소수 구하는 식
		if(N2>10000000) {
			for(i=N1; i<=10000000; i++) {
				if(prime[i]==true)
					palindrome(i);
			}
		}
		else {
			for(i=N1; i<=N2; i++) {
				if(prime[i]==true)
					palindrome(i);
			}
		}
		
		System.out.println(-1);
	}

}
