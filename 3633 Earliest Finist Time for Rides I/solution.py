from typing import List


class Solution:

    def earliestFinishTime(self, landStartTime : List[int], landDuration : List[int], waterStartTime : List[int], waterDuration : List[int]) -> int:
        curr_min = 10e8
        for i in range(len(landDuration)):
            for j in range(len(waterDuration)):
                temp = 0
                if waterStartTime[j] < landStartTime[i]:
                    if waterDuration[j] + waterStartTime[j] <= landStartTime[i]:
                        temp = landStartTime[i] + landDuration[i]
                    else:
                        temp = waterStartTime[j] + waterDuration[j] + landDuration[i]
                else:
                    if landStartTime[i] + landDuration[i] <= waterStartTime[j]:
                        temp = waterStartTime[j] + waterDuration[j]
                    else:
                        temp = landStartTime[i] + landDuration[i] + waterDuration[j]
                curr_min = temp if temp < curr_min else curr_min
        return curr_min


print(Solution().earliestFinishTime([1000], [1000], [1000], [1000]))


