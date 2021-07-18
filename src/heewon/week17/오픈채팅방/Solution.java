package ¿ÀÇÂÃ¤ÆÃ¹æ;

import java.util.*;

public class Solution {
	static HashMap<String, String> map=new HashMap<>();
	
	public static String[] solution(String[] record) {
		String elc, uid, nick="";
		StringTokenizer st;
		int j=0; int answer_length=0;
		
		for(int i=0; i<record.length; i++) {
			st=new StringTokenizer(record[i]);
			elc=st.nextToken();
			uid=st.nextToken();
			
			if(elc.equals("Enter")) {
				nick=st.nextToken();
				map.put(uid, nick);
				answer_length++;
			}
			else if(elc.equals("Change")) {
				nick=st.nextToken();
				map.put(uid, nick);
			}
			else if(elc.equals("Leave")) {
				answer_length++;
			}
		}
		
		String[] answer = new String[answer_length];
		for(int i=0; i<record.length; i++) {
			st=new StringTokenizer(record[i]);
			elc=st.nextToken();
			uid=st.nextToken();
			
			if(elc.equals("Enter")) {
				answer[j]=map.get(uid)+"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
				j++;
			}
			else if(elc.equals("Leave")) {
				answer[j]=map.get(uid)+"´ÔÀÌ ³ª°¬½À´Ï´Ù.";
				j++;
			}
		}
		return answer;
	}
	public static void main(String[] args) {
		String[] record= {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
		
		String result[]=solution(record);
		for(int i=0; i<result.length; i++)
			System.out.println(result[i]);
	}

}
