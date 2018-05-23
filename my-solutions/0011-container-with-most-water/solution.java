class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length-1;
        int vol = 0;
        while(l<r){
            if(vol < (r-l)*Math.min(height[l], height[r]))
                vol = (r-l)*Math.min(height[l], height[r]);
            if(height[r]<height[l])
                r--;
            else
                l++;
        }
        return vol;
    }
}
