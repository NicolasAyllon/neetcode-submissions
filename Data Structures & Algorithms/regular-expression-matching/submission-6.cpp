class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        return dfs(0, 0, s, p, m, n);
    }

    bool dfs(int i, int j, const string& s, const string& p, int m, int n) {
        if (j == n) return i == m;

        bool match = (i < m && (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < n && p[j + 1] == '*') {
            return dfs(i, j + 2, s, p, m, n) || 
                   (match && dfs(i + 1, j, s, p, m, n));
        }

        if (match) {
            return dfs(i + 1, j + 1, s, p, m, n);
        }

        return false;
    }
};