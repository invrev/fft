//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//Each number in C may only be used once in the combination.
//Note:
//All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
//A solution set is: 
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
//
void genSolution(int last_choice,int level,int choice,vector<int>&candidates,vector<int>& local_store,int& local_result
   ,int target,vector< vector<int> >&result) {
       if(local_result == target) {
           result.push_back(local_store);
       } else {
           level += 1;
             for(int i=last_choice;i<candidates.size();i++) {
                                 if(local_result + candidates[i] <= target) {
                local_result += candidates[i];
                local_store.push_back(candidates[i]);
                genSolution(i+1,level,choice,candidates,local_store,local_result,target,result);
                local_result -= candidates[i];
                local_store.pop_back();
                                 }
          }
       }
}
vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int> > result;
       int level = 0;
       int choice = 0;
       int local_result = 0;
       sort(candidates.begin(),candidates.end());
       vector<int> local_store;
       int last_choice = 0;
       genSolution(last_choice,level,choice,candidates,local_store,local_result,target,result);
       return result;
}
