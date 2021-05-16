//결과 틀렸다고 뜸
//다시 풀기


import java.util.HashMap;
import java.util.Scanner;

public class Read_english {
		
	static String count_print(String find) {

		int len2=find.length();	
		HashMap<Character, Integer> hm=new HashMap<>();
		for (int j=1; j<len2-1; j++) {
			hm.put(find.charAt(j), hm.getOrDefault(find.charAt(j), 0)+1);
		}
		String result=hm.toString();
		
		return result;
	}
	
	public static void main(String[] args) {
		
		Scanner sc= new Scanner(System.in);
		int N, M, i, len, j, k;
		int result=0;
		
		//사전에 있는 값 입력
		N=sc.nextInt();
		sc.nextLine();
		String exist[]=new String[N];
		for(i=0; i<N; i++)
			exist[i]=sc.nextLine();	
		M=sc.nextInt();
		sc.nextLine();
		
		String result_exist[]= new String[N];
		
		//사전에 있는 값 해시맵
		for(i=0; i<N; i++) {
			HashMap<Character, Integer> hm2=new HashMap<>();
			len=exist[i].length();
			for (j=1; j<len-1; j++) {
				hm2.put(exist[i].charAt(j), hm2.getOrDefault(exist[i].charAt(j), 0)+1);
			}
			result_exist[i]=hm2.toString();
		}
		
		//문장 입력
		
		String tmp[]= {};
		String final_result="";
		for(i=0; i<M;i++) {
			tmp=sc.nextLine().split(" ");
			int tmp_result=0;
			for(j=0; j<tmp.length; j++) {
				result=0;
				String tmp_str=count_print(tmp[j]);
				for (k=0; k<N; k++) {
					int exist_len=exist[k].length(); int find_len=tmp[j].length();
					if (exist_len!=find_len) continue;
					else if (exist[k].charAt(0)!=tmp[j].charAt(0) || exist[k].charAt(exist_len-1) != tmp[j].charAt(find_len-1)) continue;
					else {
						if(result_exist[k].equals(tmp_str))
							result+=1;
					}
				}
				if(result>0 && tmp.length>1 && tmp_result!=0) {
						tmp_result*=result;
				}
				else if(tmp_result==0) {
					tmp_result+=result;
				}		
			}
			final_result+=tmp_result+"\n";
		}
		System.out.println(final_result);
	}
}
