class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map <Integer, Integer> h = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            Integer temp = h.get(nums[i]);
            if(temp != null){
                if(temp != i){
                    int result[] = new int[2];
                    result[0] = i;
                    result[1] = temp;
                    return result;
                }
            }
            else{
                h.put(target - nums[i], i);
            }
        }
        int result[] = new int[2];
                result[0] = -1;
                result[1] = -1;
                return result;
    }
}
