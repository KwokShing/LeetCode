package Medium.p406;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by Krossing on 12/30/16.
 */
public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        List<int[]> l = new LinkedList<>();
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] != o2[0])
                    return o2[0] - o1[0];
                return o1[1] - o2[1];
            }
        });
        for (int i = 0; i < people.length; ++i) {
            l.add(people[i][1], people[i]);
        }
        return l.toArray(new int[people.length][]);
    }
}