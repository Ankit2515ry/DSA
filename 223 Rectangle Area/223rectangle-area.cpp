class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area=(abs(ax2-ax1)*abs(ay2-ay1))+(abs(bx2-bx1)*abs(by2-by1));
        int xmi=max(ax1,bx1);
        int xma=min(ax2,bx2);
        int ymi=max(ay1,by1);
        int yma=min(ay2,by2);
        int cx=max(0,(xma-xmi));
        int cy=max(0,(yma-ymi));
        area-=cx*cy;
        return area;
    }
};