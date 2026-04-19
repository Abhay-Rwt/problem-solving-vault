select today.id as Id from Weather today
cross join Weather yesterday
where datediff(today.recordDate, yesterday.recordDate) = 1
and today.temperature > yesterday.temperature