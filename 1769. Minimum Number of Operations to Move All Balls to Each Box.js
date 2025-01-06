var minOperations = function(boxes) 
{
    let n = boxes.length
    let ans = Array(n).fill(0);
    let oneCount = 0, operation = 0;
    for(let i = 0; i < n; i++)
    {
        ans[i] += operation;
        oneCount += boxes[i] == '1';
        operation += oneCount;
    }
    oneCount = 0, operation = 0;
    for(let i = n - 1; i >= 0; i--)
    {
        ans[i] += operation;
        oneCount += boxes[i] == '1';
        operation += oneCount;
    }
    return ans;    
};