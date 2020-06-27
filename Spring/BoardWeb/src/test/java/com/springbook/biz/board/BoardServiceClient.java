package com.springbook.biz.board;

import java.util.List;

import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

public class BoardServiceClient {
	
	public static void main(String[] args) {
		// 1. Spring 컨테이너를 구동한다.
		AbstractApplicationContext container = new GenericXmlApplicationContext("applicationContext.xml");
		
		// 2. Spring 컨테이너로 부터 BoardServiceImpl 객체를 Lookup 한다.
		BoardService boardService = (BoardService)container.getBean("boardService");
		
		// 3. 글 등록 기능 테스트
		BoardVO vo = new BoardVO();
		vo.setTitle("임시 제목");
		vo.setWriter("홍길동");
		vo.setContent("임시 내용..............");
		// Transaction 실습
		//vo.setSeq(100);
		// Transaction 실습을 위해 주석 처리
		boardService.insertBoard(vo);
		
		// 글 삭제 기능 테스트
		/*
		BoardVO vo = new BoardVO();
		vo.setSeq(3);
		boardService.deleteBoard(vo);
		*/
		
		// 4. 글 목록 검색 기능 테스트
		List<BoardVO> boardList = boardService.getBoardList(vo);
		for (BoardVO board : boardList) {
			System.out.println("---> " + board.toString());
		}
		
		// 5. Spring 컨테이너 종료
		container.close();
	}

}
