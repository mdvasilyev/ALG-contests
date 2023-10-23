#include <iostream>
#include <vector>
#include <queue>


std::vector<std::vector<long long>> find_minima(std::vector<std::vector<long long>> matrix, int l){

    long long m = matrix.size();
    long long n = matrix[0].size();
   
    std::vector<std::vector<long long>> ans(m - l + 1, std::vector<long long>(n - l + 1));   
    std::vector<std::deque<int>> deq(n);
    
    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < l - 1; ++i)
        {
            int x = matrix[i][j];
            while (!deq[j].empty() && matrix[deq[j].back()][j] >= x)
                deq[j].pop_back();
            deq[j].push_back(i);
        }
    }
    
    for(int i = l - 1; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int x = matrix[i][j];
            while (!deq[j].empty() && matrix[deq[j].back()][j] >= x)
                deq[j].pop_back();
            deq[j].push_back(i);
            if (deq[j].size() > 1 && deq[j].front() <= i - l)
                deq[j].pop_front();
        }
        std::deque<std::pair<int,int>> idx;
        for (int j = 0; j < l - 1; ++j)
        {
            int row = deq[j].front();
            int x = matrix[row][j];
            while (!idx.empty() && matrix[idx.back().first][idx.back().second] >= x)
                idx.pop_back();
            idx.push_back({row, j});
        }
            
        for (int j = l - 1; j < n; ++j)
        {
            int row = deq[j].front();
            int x = matrix[row][j];
            while (!idx.empty() && matrix[idx.back().first][idx.back().second] >= x)
                idx.pop_back();
            idx.push_back({row, j});
            if(idx.size() > 1 && idx.front().second <= j - l)
                idx.pop_front();
            ans[i - l + 1][j - l + 1] = matrix[idx.front().first][idx.front().second];
        }
    }
    return ans;
}


int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, l;
    std::cin >> n >> l;
    std::vector<long long> row(n);
	std::vector<std::vector<long long>> matrix(n, row);
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
            std::cin >> matrix[i][j];
    }
    std::vector<std::vector<long long>> res = find_minima(matrix, l);
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
            std::cout << res[i][j] << ' ';
        std::cout << std::endl;
    }
    return 0;
}
