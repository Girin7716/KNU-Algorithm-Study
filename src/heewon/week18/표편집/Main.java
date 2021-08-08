
import java.util.Stack;

class Main {
	public String solution(int n, int k, String[] cmd) {
        String answer = "";
        Stack <Integer> del=new Stack<Integer>();
        
        int i; int j=0; int tmp_n=n;
        for(i=0; i<cmd.length; i++) {
        	if(cmd[i].contains("D")) {
        		k += Integer.parseInt(cmd[i].split(" ")[1]);
        	}
        	if(cmd[i].contains("U")) {
        		k -= Integer.parseInt(cmd[i].split(" ")[1]);
        	}
        	if(cmd[i].contains("C")) {
        		del.add(k);
        		tmp_n--;
        		if(k>=tmp_n) {
        			k--;
        		}
        	}
        	if(cmd[i].contains("Z")) {
        		if(del.pop()<=k)
        			k++;
        		tmp_n++;
        	}
        }

        StringBuilder builder = new StringBuilder();
        for(i=0; i<tmp_n; i++)
            builder.append("O");
        while(!del.isEmpty()) {
            builder.insert(del.remove(del.size()-1).intValue(), "X");
        }
        answer=builder.toString();
        
        return answer;
    }
}

