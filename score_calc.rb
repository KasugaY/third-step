#! /usr/bin/env ruby
#! ruby -ku
require 'numo/narray'
include Numo

#試験の成績を配列に記述
scienceArray = DFloat[65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70]
englishArray = DFloat[44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

#平均・標準偏差・合計点のプログラム
printf "理科の試験を受けた人数:%d人	英語の試験を受けた人数:%d人\n", scienceArray.size, englishArray.size
printf "理科の平均点:%.5f（点）	英語の平均点:%.5f（点）\n", scienceArray.mean, englishArray.mean
printf "理科の標準偏差:%.12f（点）	英語の標準偏差:%.12f（点）\n", scienceArray.stddev, englishArray.stddev
printf "理科の合計点:%.2f（点）	英語の合計点:%.2f（点）\n", scienceArray.sum, englishArray.sum

#偏差値表示のプログラム
SciStddev = 50 + 10 * ((scienceArray[i] - scienceArray.mean) / scienceArray.stddev)
EngStddev = 50 + 10 * ((englishArray[i] - englishArray.mean) / englishArray.stddev) 
(1..19).each{|i|
	printf  "%d人目の理科の偏差値:%.3f	英語の偏差値:%.3f\n", i, SciStddev, EngStddev 
}

#ソートのプログラム(降順)
printf "理科の高得点順\n"
p scienceArray.sort.reverse.to_a
printf "\n"
printf "英語の高得点順\n"
p englishArray.sort.reverse.to_a
printf "\n"

