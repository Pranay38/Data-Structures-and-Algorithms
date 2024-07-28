# Write your MySQL query statement below
select s.student_id,s.student_name,sb.subject_name,count(e.subject_name) as attended_exams from Students s
join Subjects sb
left join examinations e on s.student_id=e.student_id and sb.subject_name=e.subject_name
group by s.student_id,sb.subject_name
order by s.student_id asc,sb.subject_name asc