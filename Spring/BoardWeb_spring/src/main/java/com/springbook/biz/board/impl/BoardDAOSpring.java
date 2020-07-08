package com.springbook.biz.board.impl;

import java.util.List;

import javax.sql.DataSource;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.support.JdbcDaoSupport;
import org.springframework.stereotype.Repository;

import com.springbook.biz.board.BoardVO;

// BoardServiceImpl Ŭ���� �����ؾ� ��밡������ ����!

// DAO(Data Access Object)
//JdbcDaoSupport Ŭ������ ����ϴ� ���
@Repository("boardDAOSpring")
//public class BoardDAOSpring extends JdbcDaoSupport {
// JdbcTemplate Bean ��� �ǽ�
public class BoardDAOSpring {	
	// JdbcTemplate Bean ��� �ǽ�
	@Autowired
	private JdbcTemplate jdbcTemplate;

	// SQL ��ɾ��
	// Transaction �ǽ��� ���� �ּ�ó��
	private final String BOARD_INSERT = "insert into board(seq, title, writer, content) values((select nvl(max(seq), 0)+1 from board),?,?,?)";
	// Transaction �ǽ�
	//private final String BOARD_INSERT = "insert into board(seq, title, writer, content) values(?,?,?,?)";
	private final String BOARD_UPDATE = "update board set title=?,content=? where seq=?";
	private final String BOARD_DELETE = "delete board where seq=?";
	private final String BOARD_GET = "select * from board where seq=?";
	private final String BOARD_LIST = "select * from board order by seq desc";
	private final String BOARD_LIST_T = "select * from board where title like '%'||?||'% order by seq desc";
	private final String BOARD_LIST_C = "select * from board where content like '%'||?||'%' order by seq desc";

	// JdbcTemplate Bean ��� �ǽ��� ���� �ּ�ó��
	/*
	// JdbcDaoSupport Ŭ������ ����ϴ� ���
	@Autowired
	public void setSuperDataSource(DataSource dataSource) {
		super.setDataSource(dataSource);
	}
	*/
	
	// JdbcTemplate Bean ��� �ǽ��� ���� �ּ�ó��
	
	// CRUD ����� �޼ҵ� ����
	// �� ���
	public void insertBoard(BoardVO vo) {
		System.out.println("===> Spring JDBC�� insertBoard ��� ó��");
		//getJdbcTemplate().update(BOARD_INSERT, vo.getTitle(), vo.getWriter(),vo.getContent());
		// Transaction �ǽ��� ���� �ּ� ó��
		jdbcTemplate.update(BOARD_INSERT, vo.getTitle(), vo.getWriter(),vo.getContent());
		//jdbcTemplate.update(BOARD_INSERT, vo.getSeq(), vo.getTitle(), vo.getWriter(),vo.getContent());
	}

	// �� ����
	public void updateBoard(BoardVO vo) {
		System.out.println("===> Spring JDBC�� updateBoard() ��� ó��");
		//getJdbcTemplate().update(BOARD_UPDATE, vo.getTitle(), vo.getContent(), vo.getSeq());
		jdbcTemplate.update(BOARD_UPDATE, vo.getTitle(), vo.getContent(), vo.getSeq());
	}

	// �� ����
	public void deleteBoard(BoardVO vo) {
		System.out.println("===> Spring JDBC�� deleteBoard() ��� ó��");
		//getJdbcTemplate().update(BOARD_DELETE, vo.getSeq());
		jdbcTemplate.update(BOARD_DELETE, vo.getSeq());
	}

	// �� �� ��ȸ
	public BoardVO getBoard(BoardVO vo) {
		System.out.println("===> Spring JDBC�� getBoard() ��� ó��");
		Object[] args = {vo.getSeq()};
		//return getJdbcTemplate().queryForObject(BOARD_GET, args, new BoardRowMapper());
		return jdbcTemplate.queryForObject(BOARD_GET, args, new BoardRowMapper());
	}

	// �� ��� ��ȸ
	public List<BoardVO> getBoardList(BoardVO vo) {
		System.out.println("===> Spring JDBC�� getBoardList() ��� ó��");
		//return getJdbcTemplate().query(BOARD_LIST, new BoardRowMapper());
		Object[] args = {vo.getSearchKeyword()};
		if (vo.getSearchKeyword().equals("TITLE"))
		{
			return jdbcTemplate.query(BOARD_LIST_T, args, new BoardRowMapper());
		}
		else if (vo.getSearchCondition().equals("CONTENT"))
		{
			return jdbcTemplate.query(BOARD_LIST_C, args, new BoardRowMapper());
		}
		return null;
	}

}
