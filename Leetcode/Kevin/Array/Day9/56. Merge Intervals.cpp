//  Link : https://www.leetcode.com/problems/merge-intervals/

class Solution {
    public int[][] merge(int[][] a) {
        Arrays.sort(a, new Comparator<int[]>(){
        public int compare(int a[], int b[]){
            return a[0] - b[0];
        }
    });

    List<List<Integer>> ans = new ArrayList<>();

    for(int i = 0; i < a.length; i++) {
        if(ans.isEmpty()) {
            ans.add(Arrays.asList(a[i][0], a[i][1]));
        } else {
            if(a[i][0] <= ans.get(ans.size() - 1).get(1)) {
                ans.set(ans.size() - 1, Arrays.asList(ans.get(ans.size() - 1).get(0), Math.max(a[i][1], ans.get(ans.size() - 1).get(1)))); 
            } else {
                ans.add(Arrays.asList(a[i][0], a[i][1]));
            }
        }
    }

    int[][] result = new int[ans.size()][2];
    for(int i = 0; i < ans.size(); i++) {
        result[i][0] = ans.get(i).get(0);
        result[i][1] = ans.get(i).get(1);
    }

    return result;
    }
}