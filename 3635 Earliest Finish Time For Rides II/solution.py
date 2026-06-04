from typing import List


class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        land_sum = [start + duration for start, duration in zip(landStartTime, landDuration)]
        water_sum = [start + duration for start, duration in zip(waterStartTime, waterDuration)]

        land_map = {start : sum_ for start, sum_ in zip(landStartTime, land_sum)}
        water_map = {start : sum_ for start, sum_ in zip(waterStartTime, water_sum)}

        waterStartTime = sorted(waterStartTime)
        landStartTime = sorted(landStartTime)
        min_time = 10e9
        for start in land_map.keys():
            temp = land_map[start]
            index = 0
            while index < len(waterStartTime) and index < len(waterStartTime):
                if waterStartTime[index] <= temp: break
                index += 1
            if index == len(waterStartTime):
                temp = waterStartTime[len(waterStartTime) - 1] + water_map[waterStartTime[len(waterStartTime) - 1]]
            else:
                temp += water_map[waterStartTime[index]] - waterStartTime[index]
            min_time = min(min_time, temp)

        for start in water_map.keys():
            temp = water_map[start]
            index = 0
            while index < len(landStartTime) and index < len(landStartTime):
                if landStartTime[index] <= temp: break
                index += 1
            if index == len(landStartTime):
                temp = landStartTime[len(landStartTime) - 1] + land_map[landStartTime[len(landStartTime) - 1]]
            else:
                temp += land_map[landStartTime[index]] - landStartTime[index]
            min_time = min(min_time, temp)
        return min_time
    
print(Solution().earliestFinishTime([5], [3], [1], [10]))



