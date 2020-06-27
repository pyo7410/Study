package com.springbook.biz.board.impl;

import java.sql.ResultSet;
import java.sql.SQLException;

import com.springbook.biz.board.BoardVO;
import org.springframework.jdbc.core.RowMapper;

// RowMapper 객체를 queryForObject() 혹은 query() 메소드의 매개변수로 넘겨주면, 스프링 컨테이너는
// SQL 구문을 수행한 후 자동으로 RowMapper 객체의 mapRow() 메소드를 호출한다. 
public class BoardRowMapper implements RowMapper<BoardVO> {
	
	public BoardVO mapRow(ResultSet rs, int rowNum) throws SQLException {
		BoardVO board = new BoardVO();
		board.setSeq(rs.getInt("SEQ"));
		board.setTitle(rs.getString("TITLE"));
		board.setWriter(rs.getString("WRITER"));
		board.setContent(rs.getString("CONTENT"));
		board.setRegDate(rs.getDate("REGDATE"));
		board.setCnt(rs.getInt("CNT"));
		return board;
	}

}
