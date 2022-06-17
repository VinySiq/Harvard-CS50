-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT
    description
FROM
    crime_scene_reports
WHERE
    day = "28"
    AND month = "7"
    AND year = "2021"
    AND street = "Humphrey Street"
SELECT
    transcript
FROM
    interviews
WHERE
    day = "28"
    AND month = "7"
    AND year = "2021"
    AND transcript like "%bakery%"
SELECT
    activity
FROM
    bakery_security_logs
SELECT
    name
FROM
    people
    JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE
    day = "28"
    AND month = "7"
    AND year = "2021"
    AND hour = "10"
    AND minute >= "15"
    AND minute < "25"
    AND activity = "exit" -- Get the names of people who made a withdrawal that day on Fifer Street
SELECT
    DISTINCT name
FROM
    people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
    day = "28"
    AND month = "7"
    AND year = "2021"
    AND transaction_type = "withdraw"
    AND atm_location = "Fifer Street" -- Get the names of people who took the first flight on the 29th
SELECT
    name
FROM
    people
    JOIN passengers ON people.passport_number = passengers.passport_number
WHERE
    flight_id = (
        SELECT
            id
        FROM
            flights
        WHERE
            day = "29"
            AND month = "7"
            AND year = "2021"
        ORDER BY
            hour,
            minute
        LIMIT
            1
    ) -- Get the names of people who made a call of less than 1 minute on the day of the crime
SELECT
    name
FROM
    people
    JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE
    day = "28"
    AND month = "7"
    AND year = "2021"
    AND duration < "60" -- Finally, we take the intersection of all cases to get the name of the thief
SELECT
    name
FROM
    people
    JOIN passengers ON people.passport_number = passengers.passport_number
WHERE
    flight_id = (
        SELECT
            id
        FROM
            flights
        WHERE
            day = "29"
            AND month = "7"
            AND year = "2021"
        ORDER BY
            hour,
            minute
        LIMIT
            1
    )
INTERSECT
SELECT
    DISTINCT name
FROM
    people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
    day = "28"
    AND month = "7"
    AND year = "2021"
    AND transaction_type = "withdraw"
    AND atm_location = "Fifer Street"
INTERSECT
SELECT
    name
FROM
    people
    JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE
    day = "28"
    AND month = "7"
    AND year = "2021"
    AND duration < "60"
INTERSECT
SELECT
    name
FROM
    people
    JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE
    day = "28"
    AND month = "7"
    AND year = "2021"
    AND hour = "10"
    AND minute >= "15"
    AND minute < "25"
    AND activity = "exit" -- Get the destiny
SELECT
    city
FROM
    airports
WHERE
    id = (
        SELECT
            destination_airport_id
        FROM
            flights
        WHERE
            day = "29"
            AND month = "7"
            AND year = "2021"
        ORDER BY
            hour,
            minute
        LIMIT
            1
    ) -- Get the ACCOMPLICE
SELECT
    name
FROM
    people
    JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE
    day = "28"
    AND month = "7"
    AND year = "2021"
    AND duration < "60"
    AND caller = (
        SELECT
            phone_number
        FROM
            people
        WHERE
            name = "Bruce"
    )