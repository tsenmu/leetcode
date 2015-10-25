class Solution {
public:
  int getIntersectionLength(int p1, int p2, int p3, int p4) {
    if (p2 <= p3 || p1 >= p4) {
      return 0;
    }

    if (p1 <= p3 && p4 <= p2) {
      return p4 - p3;
    }

    if (p3 <= p1 && p2 <= p4) {
      return p2 - p1;
    }

    if (p2 >= p3 && p2 <= p4) {
      return p2 - p3;
    }

    if (p3 <= p1 && p1 <= p4) {
      return p4 - p1;
    }

    if (p1 <= p3 && p3 <= p2) {
      return p2 - p3; 
    }

    if (p1 <= p4 && p4 <= p2) {
      return p4 - p1;
    }
  }

  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    return (C - A) * (D - B) + (G - E) * (H - F) - getIntersectionLength(A, C, E, G) * getIntersectionLength(B, D, F, H); 
  }
};