import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        int MAX = 100001;

        int[] result = new int[MAX];
        boolean[] visited = new boolean[MAX];
        Queue<Integer> queue = new LinkedList();

        visited[N] = true;
        queue.add(N);
        result[N] = 0;

        while(!queue.isEmpty()) {
            int current = queue.remove();

            if(current == K) {
                System.out.println(result[current]);
                break;
            }
            if(current * 2 < MAX  && !visited[current * 2]) {
                queue.add(current * 2);
                result[current * 2] = result[current];
                visited[current * 2] = true;
            }
            if(current - 1 >= 0  && !visited[current - 1]) {
                queue.add(current - 1);
                result[current - 1] = result[current] + 1;
                visited[current - 1] = true;
            }
            if(current + 1 < MAX && !visited[current + 1]) {
                queue.add(current + 1);
                result[current + 1] = result[current] + 1;
                visited[current + 1] = true;
            }
        }
    }
}