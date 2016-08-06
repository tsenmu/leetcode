class Solution {
protected:
    vector<int> m_sol;
    vector<int> m_perfectSquares;
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        if (m_sol.size() == 0) {
            m_sol = vector<int>(n + 1, -1);
        }

        if (m_perfectSquares.size() == 0) {
            int number = 1;
            while (number * number <= n) {
                m_perfectSquares.push_back(number * number);
                ++number;
            }
        }
        
        if (m_sol[n] != -1) {
            return m_sol[n];
        }




        for (int i = m_perfectSquares.size() - 1; i >= 0; --i) {
            int perfectSquare = m_perfectSquares[i];
            if (perfectSquare == n)  {
                return m_sol[n] = 1;
            } else if (perfectSquare < n) {
                int proposedSol = n / perfectSquare + numSquares(n % perfectSquare);
                if (m_sol[n] == -1) {
                    m_sol[n] = proposedSol;
                } else {
                    m_sol[n] = min(m_sol[n], proposedSol);
                }
            }
        }

        return m_sol[n];
    }
};