class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for(int i=0; i<students.size();){
            while(sandwiches.size()!=0 && students[0]==sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
            }
            students.push_back(students[0]);
            students.erase(students.begin());
            if(count(students.begin(), students.end(), students[0])==students.size()){
                i=students.size();
            }
        }
        return students.size();
    }
};