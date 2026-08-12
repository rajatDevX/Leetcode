class Solution {
public:

    int minMutation(string startGene, string endGene,
                    vector<string>& bank) {

        unordered_set<string> bankSet(bank.begin(), bank.end());

        if (bankSet.find(endGene) == bankSet.end()) {
            return -1;
        }

        queue<string> q;
        q.push(startGene);

        unordered_set<string> visited;
        visited.insert(startGene);

        int mutations = 0;

        string genes = "ACGT";

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string current = q.front();
                q.pop();

                if (current == endGene) {
                    return mutations;
                }

                for (int i = 0; i < current.length(); i++) {

                    char original = current[i];

                    for (char ch : genes) {

                        current[i] = ch;

                        if (bankSet.find(current) != bankSet.end() &&
                            visited.find(current) == visited.end()) {

                            visited.insert(current);
                            q.push(current);
                        }
                    }

                    current[i] = original;
                }
            }

            mutations++;
        }

        return -1;
    }
};