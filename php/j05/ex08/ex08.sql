SELECT last_name, first_name, DATE_FORMAT(birthdate, '%Y-%m-%d') AS 'birthdate' FROM user_card WHERE EXTRACT(YEAR FROM birthdate) = 1983 ORDER BY last_name ASC;
