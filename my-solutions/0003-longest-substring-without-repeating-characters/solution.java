class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;
        HashMap<Character, Integer> H = new HashMap<Character, Integer>();
        int i = 0;
        int j = 1;
        int max = 1;
        H.put(s.charAt(i), i);
        while(j < s.length()){
            
            Integer temp = H.get(s.charAt(j));
            if(temp == null){
                if(j - i + 1 > max)
                    max = j - i + 1;
                H.put(s.charAt(j), j);
                j++;
            }
            else{
                int k = i;
                i = temp + 1;  
                while(k<i){
                    H.remove(s.charAt(k));
                    k++;
                }
            }
            
        }
        return max;
    }
}
