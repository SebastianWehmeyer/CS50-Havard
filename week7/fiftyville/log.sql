-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description 
FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street"

-- Looking for the correct interview transcript
SELECT DISTINCT (transcript)
FROM interviews
JOIN crime_scene_reports ON crime_scene_reports.day = interviews.day
WHERE crime_scene_reports.year = 2021 AND crime_scene_reports.month = 7 AND crime_scene_reports.day = 28 AND crime_scene_reports.street = "Humphrey Street";

-- Looking for license plates that left the bakery between 10:15 and 10:25
SELECT DISTINCT license_plate, minute
FROM bakery_security_logs
JOIN crime_scene_reports ON crime_scene_reports.day = bakery_security_logs.day
WHERE hour = 10 AND minute BETWEEN 15 AND 25 AND crime_scene_reports.year = 2021 AND crime_scene_reports.month = 7 AND crime_scene_reports.day = 28 AND crime_scene_reports.street = "Humphrey Street";

-- Looking for phone calls on that day
SELECT DISTINCT caller, receiver, duration
FROM phone_calls 
WHERE year = 2021 AND month = 7 AND day = 28;

-- Looking for calls that lasted less than a minute on that day
SELECT DISTINCT caller, receiver, duration
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60;

-- Looking for names of the people who left the bakery between 10:15 and 10:25 with their car and called someone and talked to them less than a minute
SELECT DISTINCT people.id, people.name
FROM people 
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE (phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60) AND (bakery_security_logs.hour = 10 AND bakery_security_logs.minute BETWEEN 15 AND 25 AND bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28);

-- Looking for the earlist flight id
SELECT DISTINCT flights.id
FROM flights
JOIN airports ON airports.id = flights.origin_airport_id
WHERE airports.city = "Fiftyville" AND flights.day = 29 AND flights.month = 7 AND flights.year = 2021
ORDER BY flights.hour, flights.minute ASC
LIMIT 1;

-- Looking if Sofia, Diana, Kelsey or Bruce took the earliest flight
SELECT name
FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = 36 AND (people.id = 398010 OR people.id = 514354 OR people.id = 560886 OR people.id = 686048);

-- Looking if Sofia, Kelsey or Bruce made an transaction at the bank on that day
SELECT name
FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE (people.id = 398010 OR people.id = 560886 OR people.id = 686048) AND (atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28);

-- Found Bruce. Now looking for the destination
SELECT DISTINCT city
FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
WHERE flights.id = 36; 

-- Found New York City. Now looking for Bruce's phone number
FROM people
WHERE id = 686048;

--Now looking for the name of the accomplice
SELECT people.name
FROM phone_calls
JOIN people ON people.phone_number = phone_calls.receiver
WHERE phone_calls.caller = "(367) 555-5533";

SELECT people.name
FROM phone_calls
JOIN people ON people.phone_number = phone_calls.receiver
WHERE phone_calls.caller = "(367) 555-5533" AND phone_calls.duration <= 60;

SELECT people.name
FROM phone_calls
JOIN people ON people.phone_number = phone_calls.receiver
WHERE phone_calls.caller = "(367) 555-5533" AND phone_calls.duration <= 60 and phone_calls.day = 28;

--Found Robin
