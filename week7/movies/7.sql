
SELECT title, rating 
FROM ratings
LEFT JOIN movies
ON movie_id = id
WHERE year = 2010
ORDER BY rating DESC, title ASC;
