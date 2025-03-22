#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <limits>
#include <string>

class Graph
{
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> g; // Représentation avec un dictionnaire

public:
    void addLink(std::string from, std::string to, double weight)
    {
        g[from].push_back(make_pair(to, weight));
    }

    void printGraph()
    {
        for (auto [vertex, neighbors] : g)
        {
            std::cout << vertex << "--->";
            for (auto [neighbor, weight] : neighbors)
            {
                std::cout << "(" << neighbor << "," << weight << ")";
            }
            std::cout << std::endl;
        }
    }

    void dfs_recursif(std::string start)
    {
        std::unordered_map<std::string, int> visited;
        for (auto &[vertex, weight] : g)
        {
            visited[vertex] = 0;
        }
        visited[start] = 1;
        for (auto [neighbor, weight] : g[start])
        {
            if (visited[neighbor] == 0)
            {
                std::cout << start << "--->" << neighbor << " (Distance:" << weight << ")" << std::endl;
                dfs_recursif(neighbor);
            }
        }
    }

    void dfs_iteratif(std::string start)
    {
        std::unordered_map<std::string, int> visited;
        std::stack<std::string> stack;
        stack.push(start);

        while (!stack.empty())
        {
            std::string position = stack.top();
            stack.pop();

            if (visited[position] == 0)
            {
                visited[position] = 1;

                for (auto [neighbor, weight] : g[position])
                {
                    if (visited[neighbor] == 0)
                    {
                        std::cout << position << "--->" << neighbor << " (Distance:" << weight << ")" << std::endl;
                        stack.push(neighbor);
                    }
                }
            }
        }
    }

    void bfs(std::string start)
    {
        std::unordered_map<std::string, bool> visited;
        std::queue<std::string> queue;
        queue.push(start);

        while (!queue.empty())
        {
            std::string position = queue.front();
            queue.pop();

            if (!visited[position])
            {
                visited[position] = true;

                for (auto [neighbor, weight] : g[position])
                {
                    if (!visited[neighbor])
                    {
                        std::cout  << position << "--->" << neighbor << " (Distance:" << weight << ")" << std::endl;
                        queue.push(neighbor);
                    }
                }
            }
        }
        std::cout << std::endl;
    }
};

int main()
{
    Graph g;
    
    g.addLink("Paris", "Lyon", 100);
    g.addLink("Paris", "Marseille", 150);
    g.addLink("Lyon", "Nice", 80);
    g.addLink("Marseille", "Nice", 70);
    g.addLink("Nice", "Paris", 200);

    g.printGraph();

    g.dfs_recursif("Nice");
    g.dfs_iteratif("Nice");
    

    return 0;
}