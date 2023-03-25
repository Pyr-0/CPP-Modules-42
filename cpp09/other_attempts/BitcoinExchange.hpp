/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:31:46 by mrojas-e          #+#    #+#             */
/*   Updated: 2023/03/18 20:02:08 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
#define BTC_HPP


#include <string>
#include <map>
#include <ctime>
//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

typedef std::map<std::time_t, float> btc_data_t;
typedef std::map<std::time_t, float> input_data_t;

btc_data_t parse_btc_csv(const std::string& filename);
input_data_t parse_input_file(const std::string& filename);
void calculate_btc_values(const btc_data_t& btc_data, const input_data_t& input_data);
bool is_valid_date(const std::string& date_str);
#endif // BTC_HPP
