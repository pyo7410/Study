package com.springbook.biz.board.impl;

import java.sql.ResultSet;
import java.sql.SQLException;

import com.springbook.biz.board.BoardVO;
import org.springframework.jdbc.core.RowMapper;

// RowMapper ��ü�� queryForObject() Ȥ�� query() �޼ҵ��� �Ű������� �Ѱ��ָ�, ������ �����̳ʴ�
// SQL ������ ������ �� �ڵ����� RowMapper ��ü�� mapRow() �޼ҵ带 ȣ���Ѵ�. 
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
