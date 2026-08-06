class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dest, unordered_set<string>& visited) {

        if (src == dest)
            return 1.0;

        visited.insert(src);

        for (auto& neighbour : graph[src]) {

            string next = neighbour.first;
            double weight = neighbour.second;

            if (visited.count(next))
                continue;

            double ans = dfs(next, dest, visited);

            if (ans != -1.0)
                return weight * ans;
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        for (int i = 0; i < equations.size(); i++) {

            string u = equations[i][0];
            string v = equations[i][1];

            graph[u].push_back({v, values[i]});
            graph[v].push_back({u, 1.0 / values[i]});
        }

        vector<double> result;

        for (auto& q : queries) {

            string src = q[0];
            string dest = q[1];

            if (!graph.count(src) || !graph.count(dest)) {
                result.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;

            result.push_back(dfs(src, dest, visited));
        }

        return result;
    }
};